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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b;
    cin>>a>>b;

    cout<<((a<=8 && b<=8) ? "Yay!" : ":(")<<endl;

    return 0;
}