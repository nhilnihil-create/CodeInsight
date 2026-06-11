#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; 
	cin>>n;
    pair<pair<string,int>,int> a[101];
    for(int i=0;i<n;i++){
        string s;
        int x;
        cin>>s>>x;
        a[i]=make_pair(make_pair(s,-1*x),i+1);
    }
    sort(a,a+n);
     for(int i=0;i<n;i++){
         cout<<a[i].second<<"\n";
     }
}
