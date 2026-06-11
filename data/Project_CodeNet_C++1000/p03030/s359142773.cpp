#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n;
    vector<tuple<string,int,int>> p(n);
    for (int i = 0; i < n; i++)
    {
        string x;
        int a;
        cin >> x >> a;
        tuple<string,int,int> t(x,-a,i+1);
        p[i] = t;
    }
    sort(p.begin(),p.end());
    for (int i = 0; i < n; i++)
    {
        cout << get<2>(p[i]) << endl;
    }
    

    

}