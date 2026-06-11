#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
vector<int> x = {1,-1,0,0};
vector<int> y = {0,0,-1,1};
int main(){
    string s;
    cin >> s;
    string head,tail;
    string ans = "keyence";
    head = s.substr(0,7);
    tail = s.substr(s.size()-7);
    string a,b,c,d,e,f;
    a = s.substr(0,1)+s.substr(s.size()-6);
    b = s.substr(0,2)+s.substr(s.size()-5);
    c = s.substr(0,3)+s.substr(s.size()-4);
    d = s.substr(0,4)+s.substr(s.size()-3);
    e = s.substr(0,5)+s.substr(s.size()-2);
    f = s.substr(0,6)+s.substr(s.size()-1);
    if(a==ans||b==ans||c==ans||d==ans||e==ans||f==ans||head==ans||tail==ans){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    

  return 0;
}