#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    int pre=0;
    string s1,s2;
    cout<<0<<endl;
    cin>>s1;
    if(s1=="Vacant")return 0;
    int left=0,right=n;
    while(right-left>1){
        int mid=(left+right)/2;
        cout<<mid<<endl;
        cin>>s2;
        if(s2=="Vacant")return 0;
        if((mid%2==left%2&&s1==s2)||(mid%2!=left%2&&s1!=s2)){
            left=mid;
            s1=s2;
        }else{
            right=mid;
        }
    }
    cout<<left<<endl;
}
