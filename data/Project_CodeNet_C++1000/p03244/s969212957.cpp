#include<bits/stdc++.h>
#define REP(i, n) for(int i=0; i<n; i++)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    int odda[N/2];
    int evea[N/2];
    map<int, int> mo;
    map<int, int> me;
    for (int i = 0; i < N/2; i++)
    {
        cin >> odda[i];
        cin >> evea[i];
        mo[odda[i]]++;
        me[evea[i]]++;
    }
    int omax = -1;
  	int osecm = -1;
    int numo = -1;
    int seco = -1;
    int emax = -1;
  	int esecm = -1;
    int nume = -1;
    int sece = -1;
    for (auto x : mo)
    {
        if(x.second>omax){
            seco = numo;
          	osecm = omax;
            numo = x.first;
            omax = x.second;
        }else if(x.second>osecm){
          	seco = x.first;
          	osecm = x.second;
        }
    }
    for (auto x : me)
    {
        if(x.second>emax){
            sece = nume;
          	esecm = emax;
            nume = x.first;
            emax = x.second;
        }else if(x.second>esecm){
          	sece = x.first;
          	esecm = x.second;
        }
    }
    int ans = 0;
    if(numo!=nume){
        for (int i = 0; i < N/2; i++)
        {
            if(odda[i]!=numo)ans++;
        }
        for (int i = 0; i < N/2; i++)
        {
            if(evea[i]!=nume)ans++;
        }
        
    }else{
        int tmp1=0, tmp2=0;
        for (int i = 0; i < N/2; i++)
        {
            if(odda[i]!=seco)tmp1++;
        }
        for (int i = 0; i < N/2; i++)
        {
            if(evea[i]!=nume)tmp1++;
        }
        for (int i = 0; i < N/2; i++)
        {
            if(odda[i]!=numo)tmp2++;
        }
        for (int i = 0; i < N/2; i++)
        {
            if(evea[i]!=sece)tmp2++;
        }
        ans = min(tmp1, tmp2);
    }
    cout << ans << endl;
}