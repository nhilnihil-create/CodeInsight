#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main() {
    string s;
    cin >> s;
    int a=s[0] - '0', b=s[1] - '0', c=s[2] - '0', d=s[3] - '0';
    int n=3, sum=a;
    for(int bit = 0; bit < (1<<n); ++bit){
        if(1 & bit){
            sum+=b;
        }else{
            sum-=b;
        }if(2 & bit){
            sum+=c;
        }else{
            sum-=c;
        }if(4 & bit){
            sum+=d;
        }else{
            sum-=d;
        }
        if(sum==7){
            cout << a;
            if(1 & bit){
                cout << '+' << b;
            }else{
                cout << '-' << b;
            }
            if(2 & bit){
                cout << '+' << c;
            }else{
                cout << '-' << c;
            }
            if(4 & bit){
                cout << '+' << d << '=' << 7 << "\n";
            }else{
                cout << '-' << d << '=' << 7 << "\n";
            }
            return 0;
        }
        sum=a;
    }
}
