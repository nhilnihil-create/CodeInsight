#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{   int n,k;
cin>>n>>k;
    string s;
    cin>>s;
    vector<pair<int,int>> a;
    vector<pair<int,int>> b;
    if(s[0]=='0'){
        b.push_back({0,0});
    }
    int i=0;
    while(i<s.size()){
        if(s[i]=='0'){
            int z=i;
            i++;
            while(s[i]=='0'){
                i++;
            }
            int x=i;
            a.push_back(make_pair(z,x));
        }
        else{
            int z=i;
            i++;
            while(s[i]=='1'){
                i++;
            }
            int x=i;
            b.push_back(make_pair(z,x));
        }
    }
    b.push_back({0,0});
//    for(int i=0;i<a.size();i++){
//        cout<<a[i].first<<" "<<a[i].second<<endl;
//    }
//    for(int i=0;i<b.size();i++){
//        cout<<b[i].first<<" "<<b[i].second<<endl;
//    }
    if(a.size()==0 || a[0].second-a[0].first==s.size() || a.size()<=k){
        cout<<s.size();
        return 0;
    }
    else{
        int m=INT_MIN,o=INT_MIN;
        for(int i=0;i+k<=a.size();i++){
            int l=0;
            for(int j=0;j<k;j++){
                if(!j){
                    l+=(b[i+j].second-b[i+j].first)+(a[i+j].second-a[i+j].first)+(b[i+j+1].second-b[i+j+1].first);
                }
                else{
                    l+=(a[i+j].second-a[i+j].first)+(b[i+j+1].second-b[i+j+1].first);
                }
            }
            m=max(m,l);
        }

        cout<<m;
        return 0;
    }
}