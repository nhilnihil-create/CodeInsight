#include <bits/stdc++.h>
using namespace std;
#define MD 1000000007
typedef long long int ll;
typedef pair<ll, ll> P;
template <typename T>
std::string tostr(const T &t){std::ostringstream os;os << t;return os.str();}
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

int main()
{
    string s;
    cin>>s;
    vector<string> v{"AKIHABARA","AKIHABAR","AKIHABRA","AKIHABR",
    "AKIHBARA","AKIHBAR","AKIHBRA","AKIHBR",
    "KIHABARA","KIHABAR","KIHABRA","KIHABR",
    "KIHBARA","KIHBAR","KIHBRA","KIHBR"};
    for(int i=0;i<16;i++){
        if(s==v[i]){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}