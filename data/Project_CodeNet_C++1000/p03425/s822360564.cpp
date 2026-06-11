#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(){
    int n; cin >> n;
    vector<string> s(100000);
    set<char> march;
    march.insert('M'); march.insert('A'); march.insert('R');
    march.insert('C'); march.insert('H');
    map<char, ull> memo;
    memo['M']=0; memo['A']=0; memo['R']=0;
    memo['C']=0; memo['H']=0;
    for(int i=0; i<n; i++){
        cin >> s[i];
        char init = s[i].at(0);
        if(march.count(init)){
            memo[init]++;
        }
    }

    ull ans=0;
    vector<ull> num(5, 0);
    num[0] = memo['M']; num[1]=memo['A']; num[2]=memo['R'];
    num[3] = memo['C']; num[4]=memo['H'];
    int P [10]={0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,2};
    int Q [10]={1 ,1 ,1 ,2 ,2 ,3 ,2 ,2 ,3 ,3};
    int R [10]={2 ,3 ,4 ,3 ,4 ,4 ,3 ,4 ,4 ,4};

    for(int i=0; i<10; i++){
        ans += num[P[i]]*num[Q[i]]*num[R[i]];
    }
    cout << ans << endl;
    return 0;
}