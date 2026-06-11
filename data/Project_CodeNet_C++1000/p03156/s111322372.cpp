//Author: master19
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ulli unsigned long long int
#define lli long long int 
#define crap ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define f first 
#define s second 
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define endl "\n"
#define mod 1000000007
int main(){
    ll num, a, b, temp;
    cin >> num;
    ll lessA = 0, greaterA = 0, greaterB = 0;
    cin >> a >> b;
    for(int i=0;i<num; i++){
        cin >> temp;
        if(temp <= a)
            lessA++;
        else if(temp <= b)
            greaterA++;
        else    
            greaterB++;
    }
    cout << min(lessA, min(greaterA, greaterB)) << endl;
}
