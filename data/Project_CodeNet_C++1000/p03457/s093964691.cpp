#include <bits/stdc++.h>
using namespace std;
int amaji(int y,int x,int n1)
{
    if(x%n1==y%n1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int main(void){ /*メイン関数を入れる*/
    int n,t[100000],x[100000],y[100000],i=0,z,k;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> t[i] >> x[i] >> y[i];
    }
    if(t[0]%2!=(x[0]+y[0])%2)
    {
         cout << "No" << endl;
         return 0;
    }     
    else if(t[0]<x[0]+y[0])
    {
         cout << "No" << endl;
         return 0;
    }

    for(i=1;i<n;i++)
    {
        z=t[i]-t[i-1];
        
        if(z%2!=abs((x[i]+y[i])-(x[i-1]+y[i-1]))%2)
        {
            cout << "No" << endl;
            return 0;
        }
        else if(z<abs((x[i]+y[i])-(x[i-1]+y[i-1])))
        {
            cout << "No" << endl;
            return 0;
        }
    }
            
    cout << "Yes" << endl;
    //わからへん;;
    //もうやりたくないぜ。
    //WAでるな yattaka!?
    //uyeshota
    //※これはA問題ではありません

    return 0;

}
