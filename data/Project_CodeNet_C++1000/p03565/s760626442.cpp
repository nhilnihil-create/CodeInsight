// ABC76-C
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v) //vectorの中身を見る
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    string s,t;
    cin>>s>>t;
    bool flag=true;
    int sl=s.size(),tl=t.size();
    int max_l=-1,max_r=-1;
    if(sl<tl) flag=false;
    else{
        for(int i=0;i<sl;i++){ //先頭
            int r=i+tl-1;
            if(sl<=r) break;
            int num=0;
            bool flag2=true;
            for(int j=i;j<=r;j++){
                if(s[j]!=t[num] &&s[j]!='?'){
                    flag2=false;
                    break;
                }
                num++;
            }
            if(flag2) max_l=i,max_r=r;
        }
        if(max_r==-1) flag=false;
    }
    if(flag){
        int num=0;
        for(int i=0;i<sl;i++){
            if(max_l<=i && i<=max_r) s[i]=t[num],num++;
            else{
                if(s[i]=='?') s[i]='a';
            }
        }
        cout<<s<<endl;
    }else{
        cout<<"UNRESTORABLE"<<endl;
    }
    return 0;
}