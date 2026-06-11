#include <bits/stdc++.h>

using namespace std;
int sumdigit(int n) {
    int ret = 0;
    while(n) {
        ret += n%10;
        n/=10;
    }
    return ret;
}
int main(void) {
    int N,A,B;
    int sum,total = 0;
    cin >> N >> A >> B;
    for(int i=1;i<=(int)N;i++) {
        sum = sumdigit(i);
        if(A <= sum && sum <= B) {
//            printf("sum:%d\n", sum);
            total += i;
        }
    }

    cout << total << endl;    
}