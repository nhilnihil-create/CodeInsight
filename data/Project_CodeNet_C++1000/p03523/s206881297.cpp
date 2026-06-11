#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    string s;
    cin>>s;
    string t="KIHBR";
    if(s=="KIHBR"||s=="AKIHBR"||s=="KIHABR"||s=="KIHBAR"||s=="KIHBRA"||s=="AKIHABR"||s=="AKIHBAR"||s=="AKIHBRA"||s=="KIHABAR"||s=="KIHABRA"
    ||s=="KIHBARA"||s=="AKIHABAR"||s=="KIHABARA"||s=="AKIHABARA"){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}
