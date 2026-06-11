#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll n;
    cin>>n;
    vector<ll> a[3],b,c;
    ll now = 2;
    if(n==3){
        cout << "2 5 63\n";
        return 0;
    }
    if(n==4){
        cout << "2 5 20 63\n";
        return 0;
    }
    for(int i=2;i<=30000;i++){
        if(i%2 && (i%3)==0) b.push_back(i);
        else if(i%3 && (i%2)==0) a[i%3].push_back(i);
        else if(i%3==0 && i%2==0) c.push_back(i);
    }
    cerr << a[1].size() << " " << a[2].size() <<  " " << b.size() << " "<< c.size() << endl;
    int cnt = 0;
    while(cnt < 5000 && n>=4){
        cout << b[cnt] << " " << b[cnt+1] << " ";
        cnt+=2;
        n-=2;
    }
    cnt = 0;
    while(cnt < 5000 && n>=2){
        cout <<a[1][cnt] << " " << a[2][cnt] << " ";
        cnt++;
        n-=2;
    }
    cnt =0 ;
    while(n){
        n--;
        cout << c[cnt] << " ";
        cnt++;
    }

}