#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    cin >> a.at(i);

    sort(a.begin(),a.end());

    int cnt=0;
   
    for(int i=0; i<n; i++){
        if(x - a.at(i) >0 && i==n-1){
            break;
        }
        else if(x - a.at(i) >= 0){
            cnt++;
            x -= a.at(i);
        }
        else{
            break;
        }

    }
    cout << cnt << endl;

}