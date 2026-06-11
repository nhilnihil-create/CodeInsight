#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    long long int n;
    vector<pair<string,int>>a(1000);
    vector<pair<string,int>>b(1000);
    cin>>n;
    for(long long int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        a[i].second*=-1;
        b[i].first=a[i].first;
        b[i].second=a[i].second;
    }
    sort(a.begin(),a.end(),greater<>());
    for(long long int i=0;i<n;i++){
        for(long long int j=0;j<n;j++){
            if(a[n-1-i].first==b[j].first&&a[n-1-i].second==b[j].second){
                cout<<j+1<<endl;
            }
        }
    }
    return 0;
}
