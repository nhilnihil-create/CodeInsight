#include <bits/stdc++.h>
namespace std {
    template <>
    class hash<std::pair<string, string>> {
    public:
        size_t operator()(const std::pair<string, string>& x) const{
            return hash<string>()(x.first) ^ hash<string>()(x.second);
        }
    };
}
using namespace std;
#define int long long



signed main(){
    int n;
    cin >>n;
    char s1[n],s2[n];
    for(int i=0;i<n;i++)cin >> s1[i];
    for(int i=n-1;i>=0;i--)cin >> s2[i];
    unordered_map<pair<string,string>,int> p1;
    int k=pow(double(2),double(n)),k0;
    string k1="",k2="";
   
    for(int i=0;i<k;i++){
        k0=i;
        k1="";k2="";
        for(int j=0;j<n;j++){
            if(k0%2==0)k1.push_back(s1[j]);
            else k2.push_back(s1[j]);
            k0 /=2;
        }
      //  cerr << k1[0]<<endl;
        p1[make_pair(k1,k2)]++;
    }
    int ans=0;
    for(int i=0;i<k;i++){
        k0=i;
        k1="";k2="";
        for(int j=0;j<n;j++){
            if(k0%2==0)k1.push_back(s2[j]);
            else k2.push_back(s2[j]);
            k0 /=2;
        }
        if(p1.find(make_pair(k1,k2))!=p1.end())ans+=p1.at(make_pair(k1,k2));
        
    }
    cout <<ans;

    return 0;
}