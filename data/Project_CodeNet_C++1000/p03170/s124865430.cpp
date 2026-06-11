#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numIntegers;
    cin >> numIntegers;
    int numStones;
    cin >> numStones;

    vector<int> integers(numIntegers);
    for(int& integer : integers) {
        cin >> integer;
    }

    vector<bool> memo(numStones+1, false);

    for(int i = 0; i <= numStones; i++) {
        for(int integer : integers) {
            if(i >= integer && !memo[i-integer]) memo[i] = true;
        }
    }

    if(memo[numStones]) {
    	cout << "First";
    } else {
    	cout << "Second";
    }

    return 0;
}