#include<bits/stdc++.h>
using namespace std;

string solve(vector<int>& xs, int k){
    //Testa todos os pares distintos de antenas
    for(int i=0;i<5;i++)
        for(int j=i+1;j<5;j++)
            if(xs[j] - xs[i] > k)
                return ":(";
    
    return "Yay!";
}

int main(){
    vector<int> xs(5);

    for(int i=0;i<5;i++)
        cin>>xs[i];
    
    int k;
    cin>>k;

    auto ans = solve(xs,k);

    cout<<ans<<"\n";

    return 0;
}