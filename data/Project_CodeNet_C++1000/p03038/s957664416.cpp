#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    long long sum=0;
    vector<int> a(n);
    vector<pair<int,int>> b(m);
    for(int i=0;i<n;i++){
        cin >> a.at(i);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++){
        cin >> b.at(i).second >> b.at(i).first;
    }

    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    reverse(a.begin(),a.end());
    int aind=0,bind=0,limit=n;
    bool che = true;
    while(limit>0){
        limit--;
        if(b.at(bind).first>a.at(aind)&&bind<m&&che==true){
            sum += b.at(bind).first;
            b.at(bind).second--;
            if(b.at(bind).second==0&&bind<m){
                if(bind==m-1){
                    che = false;
                }else{
                    bind++;
                }
            }
        }else if(aind<n){
            sum += a.at(aind);
            aind++;
        }
        //cout << bind << endl;
        /*for(int i=0;i<n;i++){
            cout << "," <<a.at(i);
        }
        cout << endl;*/
    }
    /*for(int i=0;i<n;i++){
        //cout << a.at(i) << endl;
        sum += a.at(i);
    }*/
    cout << sum << endl;
}