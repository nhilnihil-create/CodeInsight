#include <iostream>
#include <vector>
using namespace std;

int numPlates;
double memo[301][301][301];
double solve(int one, int two, int three) {
    if(one < 0 || two < 0 || three < 0) return 0;

    if(three == 0 && two == 0 && one == 0) return 0;

    if(memo[one][two][three] > 0) return memo[one][two][three];

    int remaining = one + two + three;

    double expVal = numPlates +
                    one*solve(one-1,two,three) + 
                    two*solve(one+1,two-1,three) +
                    three*solve(one,two+1,three-1);
    
    memo[one][two][three] = expVal/remaining;
    return memo[one][two][three];
}

int main() {
    cin >> numPlates;
    int one = 0, two = 0, three = 0;

    for(int i = 0; i < numPlates; i++) {
        int numSushi;
        cin >> numSushi;
        if(numSushi == 1) {
            one++;
        } else if(numSushi == 2) {
            two++;
        } else {
            three++;
        }
    }
    
    memset(memo, -1, sizeof memo);

    double result = solve(one, two, three);
	printf("%.15f", result);
    return 0;
}