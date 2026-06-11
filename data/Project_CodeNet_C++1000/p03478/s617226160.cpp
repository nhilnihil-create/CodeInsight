#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    
    int ans =0;

    for(int i=1; i<=n; i++){

        int sum=0;
        int t = i;

        while(t > 0){
            sum += t%10;
            t /= 10;
        }

        if(sum >= a && sum <= b)
            ans += i;
    }

    cout << ans << endl;

}