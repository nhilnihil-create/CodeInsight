#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    string s;cin>>s;
    vector<string> vec{"KIHBR","KIHBAR","AKIHBR","KIHABR","KIHBRA","AKIHABR","AKIHBAR","AKIHBRA","KIHABAR","KIHABRA","KIHBARA","AKIHABAR","AKIHABRA","AKIHBARA","KIHABARA","AKIHABARA"};
    for(string x:vec){
        if(s==x){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}

