#include <bits/stdc++.h>
using namespace std;
int main(void){
    int m,i=0,j,c=0,n,l[100010],r[100010],max=0, min=20000000;
    cin >> n >> m;
    for(i=0;i<m;i++)
    {
        cin >> l[i] >> r[i];
        if(max<l[i])
        {
            
            max=l[i];
        }
        if(min>r[i])
        {
            min=r[i];
        }
    }
    if(min<max)
    {
        cout << "0" << endl;
    }
    else{
        
        cout << min-max+1 << endl;
    }
    return 0;

}
