#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int N;
    cin >> N;
    if(N==10||N==100||N==1000||N==10000||N==100000)    cout << 10 << endl;
    else{
        int sum=0;
        while(true){
            if(N/10==0){
                sum+=N;
                break;
            }
            else{
                sum+=N%10;
                N/=10;
            }
            
        }
        cout << sum << endl;
    }
}