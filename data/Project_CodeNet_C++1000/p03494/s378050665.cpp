#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a;
    int res=100000;
    for(int i=0; i<n; i++){
        int cnt=0;
        cin >> a;
        while(a%2 == 0){
            a /= 2;
            cnt++;
        }
        res = min(res,cnt);
    }

    cout << res << endl;

}