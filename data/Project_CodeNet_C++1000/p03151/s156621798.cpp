#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,down = 0,count = 0;
    cin >> n;
    vector<long long>a(n),b(n),margin;
    long long a_all = 0,b_all = 0,shotage = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i]; 
    }
    for(int i = 0;i < n;i++){
        cin >> b[i];
        if(a[i] < b[i])shotage += b[i] - a[i],down++;
        else if(a[i] > b[i])margin.push_back(a[i] - b[i]);
    }

    sort(margin.begin(),margin.end(),greater<long long>());

    for(int i = 0;i < (int)margin.size();i++){
        if(shotage <= 0)break;
        shotage -= margin[i];
        count++;
    }

    if(shotage > 0){
        cout << -1 << endl;
        return 0;
    }
    
    cout << down + count << endl;
}
