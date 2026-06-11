#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a(n);

    int mx = 0,ind;

    for(int i=0; i<n; i++){
        cin>>a[i];
        if(abs(a[i])>=abs(mx)){
            mx = a[i];
            ind = i;
        }
    }

    ind++;

    vector<pair<int,int>> pairs;

    for(int i=1; i<=n; i++){
        pairs.push_back(make_pair(ind,i));
    }

   if(mx >= 0){
        for(int i=1; i<n; i++){
            pairs.push_back(make_pair(i,i+1));
        }
    }

    else{
        for(int i=n; i>1; i--){
            pairs.push_back(make_pair(i,i-1));
        }
    }

    cout<<pairs.size()<<endl;

    for(int i=0; i<pairs.size(); i++){
        cout<<pairs[i].first<<" "<<pairs[i].second<<endl;
    }

    return 0;      
}