#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int getFirst10(int n){
    int numb = 0;
    while(numb < n){
        numb += 10;
    }
    return numb;
}
int main(){
    Hello
    int a[5], ans = 1e9;
    for(int i = 0; i < 5; i++)
        cin >> a[i];
    sort(a, a + 5);
    do{
        int lst = 0;
        for(int i = 0; i < 5; i++){
            if(i == 4) lst = lst + a[i];
            else lst = getFirst10(lst + a[i]);
        }
        ans = min(ans, lst);
    }
    while(next_permutation(a, a + 5));
    cout << ans;
    return 0;
}
