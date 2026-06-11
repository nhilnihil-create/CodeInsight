#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,i;
    cin >> n;

    pair< pair<string, int>, int> pr[110];

    string str;
    int val;

    for(i=0;i<n;i++){
        cin >> str >> val;
        pr[i] = make_pair(make_pair(str, -val), i+1);
    }

    sort(pr, pr+n);

    for(i=0;i<n;i++)
        cout << pr[i].second << endl;

    return 0;
}