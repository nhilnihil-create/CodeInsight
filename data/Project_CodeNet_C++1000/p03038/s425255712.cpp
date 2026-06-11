#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a.at(i);
    }
    sort(a.begin(),a.end());
    /*for(int i=0; i<n; i++){
        cout << a.at(i) << endl;
    }
    cout << endl;*/

    vector<tuple<int,int>> bc(m);
    int b,c;
    for(int i=0; i<m; i++){
        cin >> b >> c;
        bc.at(i)=make_tuple(c,b);
    }
    sort(bc.begin(),bc.end(),greater<>());
    /*for(int i=0; i<m; i++){
        cout << get<0>(bc.at(i)) << ' ' << get<1>(bc.at(i)) << endl;
    }
    cout << endl;*/

    int i=0, j=0;
    while(1){
        if(a.at(i) < get<0>(bc.at(j))){
            a.at(i)=get<0>(bc.at(j));
            get<1>(bc.at(j))--;
            if(get<1>(bc.at(j))==0) j++;
        }
        i++;
        if(i==n || j==m) break;
            //cout << get<0>(bc.at(0)) << ' ' << get<1>(bc.at(0)) << endl;
            //cout << a.at(i) << endl;
    }

    long long int ans=0;
    for(int i=0; i<n; i++){
        ans+=a.at(i);
        //cout << ans << endl;
    }
    cout << ans << endl;
}