// AGC32-A
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
namespace you {
    std::string to_string(char val) {
        return std::string(1, val);
        // return std::string{val};
        // you::to_string(char)
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int n;
    cin>>n;
    vector<int> num(n+1);
    rep(i,n) cin>>num[i+1];
    stack<int> sosa;
    vector<bool> seen(n+1,false); //trueだともう取り除いてる
    int see=0;
    bool flag=true;
    while(see<n){
        int ind=0; //残っているやつで何番目か
        int del=0; //消せるやつ
        for(int i=1;i<=n;i++){
            if(seen[i]==false) ind+=1;
            else continue;
            if(ind==num[i]) del=i;
        }
        if(del!=0){
            seen[del]=true;
            sosa.push(num[del]);
            see+=1;
        }else{
            flag=false;
            break;
        }
    }
    if(flag){
        rep(i,n){
            int a=sosa.top();
            cout<<a<<endl;
            sosa.pop();
        }
    }else cout<<-1<<endl;
    return 0;
}