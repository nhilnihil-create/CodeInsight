//WA 2
#include <bits/stdc++.h>
 
#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define ii pair<int,int>
#define qu queue <int>
#define qmax priority_queue <int>
#define qmin priority_queue <int, vector<int>,greater<int>>

using namespace std;

int solve(int k, vector<int>& xs){
    //ordena os números
    sort(xs.begin(), xs.end());

    //Multiplica o maior deles por 2, K vezes (lembrar que tá ordenado)
    xs.back() *= (1 << k); // no primeiro teste k = 0001 shiftado 1 que vez pra esquerda fica 0010

    //Soma todos os números
    return accumulate(xs.begin(), xs.end(), 0); // accumulate(first, last, sum); first, last : first and last elements of range whose elements are to be added sum : initial value of the sum.
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> xs(3);

    for(int i=0; i<3; i++)
        cin>>xs[i];
    
    int k;
    cin>>k;

    auto ans = solve(k, xs);

    cout<<ans<<endl;

    return 0;
}