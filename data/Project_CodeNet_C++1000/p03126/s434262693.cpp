#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    int check=0;
    for(int i=0;i<=m;i++) check|=(1<<i);

    for(int i=0;i<n;i++){
        int k;
        cin >> k;

        int check_now=0;
        for(int j=0;j<k;j++){
            int a;
            cin >> a;
            check_now|=(1<<a);
        }
        check&=check_now;
    }

    int cnt=0;
    for(int i=0;i<=m;i++){
        if((check>>i)&0x01) cnt++;
    }

    cout << cnt << endl;
}