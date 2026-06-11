#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int,char> P;

int main(){
    string s,t;
    cin>>s>>t;
    int n=s.length();
    vector<int> smap(26);
    vector<int> tmap(26);
    for(int i=0;i<n;i++){
        smap[s[i]-'a']++;
        tmap[t[i]-'a']++;
    }
    sort(smap.begin(),smap.end());
    sort(tmap.begin(),tmap.end());
    for(int i=0;i<smap.size();i++){
        if(smap[i]!=tmap[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}