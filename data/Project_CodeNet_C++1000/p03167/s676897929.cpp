#include <bits/stdc++.h>
using namespace std;


int main()
{   
    int h,w;
    cin >> h >> w ;
    string s[h];
    for (int i=0;i<h;i++)
        cin >> s[i] ;
    
    long long ans[h][w] ;
    for (int i=0;i<h;i++)
        for (int j=0;j<w;j++)
            ans[i][j]=(long long) 0 ;
        
    for (int i=0;i<w;i++){
        if (s[0][i]=='#')
            break ;
        ans[0][i]=(long long) 1 ;
    }
    
    for (int i=0;i<h;i++){
        if (s[i][0]=='#')
            break ;
        ans[i][0]=(long long) 1 ;
    }
    
    for (int i=1;i<h;i++)
        for (int j=1;j<w;j++)
            if (s[i][j]=='#')
                ans[i][j]=0 ;
            else 
                ans[i][j]=(ans[i][j-1]+ans[i-1][j])%(((long long)1000000000)+7) ;
    
    cout << ans[h-1][w-1] ;
    return 0 ;
}

