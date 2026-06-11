#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    double t,a;
    cin >> n;
    cin >> t >> a;
    
    int ans;
    double tmin=1e9;
    for(int i=0;i<n;i++){
        double h;
        cin >> h;
        double cal=abs(a-(t-h*0.006));
        if(tmin>cal){
            ans=i+1;
            tmin=cal;
        }
    }
    cout << ans << endl;
}