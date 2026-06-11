#include <bits/stdc++.h>

using namespace std;

int main()
{
    int set=0;
    int max=10;
    vector<int> a(5);
    for(int i=0;i<5;i++){
        cin >> a[i];
        if(max>a[i]%10 && a[i]%10!=0){
            max=a[i]%10;
            set=i;
        }
    }

    int ans=0;
    for(int i=0;i<5;i++){
        if(i!=set && a[i]%10) a[i]=a[i]/10*10+10;
        ans+=a[i];
    }

    cout << ans << endl;
}