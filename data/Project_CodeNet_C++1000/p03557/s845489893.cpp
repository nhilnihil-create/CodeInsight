#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> a,b,c;
typedef long long ll;
void input(vector <int>& v){
    for(int i = 0;i<n;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    return ;
}
bool compare1(int a,int b){
    return a > b;
}
int main(){
    cin >> n;
    ll res = 0;
    input(a);
    input(b);
    input(c);
    sort(a.begin(),a.end(),compare1);
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    for(int i = 0;i<n;i++){
        ll res1 = 0,res2 = 0;
        int index2 = upper_bound(c.begin(),c.end(),b[i]) - c.begin();
        if(index2 != n) res1 = (n - index2);
        int index1 = upper_bound(a.begin(),a.end(),b[i],compare1) - a.begin();
        if(index1 != n) res2 = (n - index1);
        res += res1 * res2;
    }
    cout << res << endl;

    return 0;
}