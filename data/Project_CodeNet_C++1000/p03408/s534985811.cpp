#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m ;

    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }
    
    cin >> m;
    vector<string> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b.at(i);
    }
    
    vector<int> c(n),d(n);

    for (int i = 0; i < n; i++)
    {
        int count = 0 ;
        for (int j = 0; j < n; j++)
        {
            if(a.at(i)==a.at(j)){
                count ++ ;
            }
        }
        c.at(i)=count;
        
    }
    
    for (int i = 0; i < n; i++)
    {
        int count = 0 ;
        for (int j = 0; j < m; j++)
        {
            if(a.at(i)==b.at(j)){
                count ++;
            }
        }
        d.at(i)=count;
        
    }   

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if(ans<c.at(i)-d.at(i)){
            ans = c.at(i)-d.at(i);
        }
    }
    cout << ans << endl;
}