#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
 
#define rep(i,n) for(ll i=0;i<(n;i++)
typedef long long ll;
using namespace std;

int main(void){
    // Your code here!
    int N;
    cin >> N;
    int cnt = 0;
    for(int i = 1;i<=N;i++){
        if(i % 2 == 1){
            int ans = 1;
            vector<int> x(i+1);
            int num = i;
            for(int j = 2;j<=i;j++){
                while(num % j == 0){
                    x.at(j)++;
                    num /= j;
                }
            }
            for(int v:x){
                ans *= v+1;
            }
            if(ans == 8){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}