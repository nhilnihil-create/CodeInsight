#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=3.141592653589793;
int finder(vector<string> vec,string w){
    auto itr=find(all(vec),w);
    int index=distance(vec.begin(),itr);
    if (index!=vec.size()){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    
    string s;
    cin>>s;
    vector<string> ss;
    for (int i=0;i<s.size();i++){
        string w="";
        for (int j=i;j<s.size();j++){
            w+=s.at(j);
            if (ss.size()<5){
                if (! finder(ss,w)){

                ss.push_back(w);
                sort(all(ss));
            }}
            else if (ss.at(4)>w){
                if (!finder(ss,w)){
                ss.push_back(w);
                sort(all(ss));
                ss.pop_back();
            }}
        }
    }
    int k;
    cin>>k;
    cout<<ss[k-1]<<endl;


    return 0;
}