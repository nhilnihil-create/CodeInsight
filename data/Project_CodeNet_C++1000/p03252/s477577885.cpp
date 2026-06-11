#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rp(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define all_acc(x) (x).begin(), (x).end(), 0LL
#define int long long
#define absSort(v) sort(a.begin(), a.end(), [](int i, int j) -> bool { return abs(i) < abs(j); });
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using ll = long long;
double pi=3.14159265359;

//出力するよ
void output_tate(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        //if (i != 0)
        //    cout << " ";
        cout << s[i]<<endl;
    }
    //cout << endl;
}

void output_yoko(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (i != 0)
            cout << " ";
        cout << s[i];//<<endl;
    }
    cout << endl;
}

int MOD = pow(10, 9) + 7;

int kaijou(int n){
    if(n==0) return 1;
    else{
        return ((n%MOD)*(kaijou(n-1)%MOD))%MOD;
    }
}

bool ispow(int n){
    int rn=sqrt(n);
    if(rn*rn==n) return true;
    else return false;
}

signed main() {
    string s,t; cin>>s>>t;

    map<char,int> s_map,t_map;
    string s_to="",t_to="";

    for(int i=0;i<s.length();i++){
        if(s_map[s[i]]==0){
            s_map[s[i]]=s_map.size()+1;
        }
        s_to+=to_string(s_map[s[i]]);
    }

    for(int i=0;i<t.length();i++){
        if(t_map[t[i]]==0){
            t_map[t[i]]=t_map.size()+1;
        }
        t_to+=to_string(t_map[t[i]]);
    }
    
    //cout<<s_to<<" "<<t_to<<endl;
    if(s_to==t_to) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
