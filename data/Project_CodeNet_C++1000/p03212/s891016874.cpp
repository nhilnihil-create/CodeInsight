#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
ll A;
ll res=0;
void add357(ll before){
    if(before > A){
        return;
    }
    add357(before*10+3);
    add357(before*10+5);
    add357(before*10+7);
    string str = to_string(before);
    vector<bool> count(3,false);
    rep0(i,str.length()){
        if(str[i]=='3'){
            count[0]=true;
        }else if(str[i]=='5'){
            count[1]=true;
        }else{
            count[2]=true;
        }
    }
    rep0(i,3){
        if(!count[i]){
            return;
        }
    }
    res++;
}

int main()
{
    cin >> A;
    add357(0);
    cout << res << endl;
}

