#include <bits/stdc++.h>
using namespace std;

int main(){
    int ans=0,n;
    cin >> n;
    vector<int> a(n);
    vector<pair<bool,int>> b(n+1);
    for(int i=0;i<n+1;i++){
        b.at(i).first=false;
        b.at(i).second=0;
    }

    for(int i=0;i<n;i++){
        cin >> a.at(i);
        b.at(a.at(i)).first=true;
        if(b.at(a.at(i)-1).first==true){
            b.at(a.at(i)).second=b.at(a.at(i)-1).second+1;
        }
    }
    for(int i=1;i<n+1;i++){
        if(ans<b.at(i).second){
            ans=b.at(i).second;
        }
    }
    cout << n-ans-1 << endl;
     
}