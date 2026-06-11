#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    int a, b, k;
    cin >> a >> b >> k;
    int arr[101] = {0};
    vector<int> v;
    int i = 1;
    while(i <= a/i){
        if(a % i == 0){
            if(i == a/i){
                arr[i]++;
            }
            else{
                arr[i]++;
                arr[a/i]++;
            }
        }
        i++;
    }
    i = 1;
    while(i <= b/i){
        if(b % i == 0){
            if(i == b/i){
                arr[i]++;
            }
            else{
                arr[i]++;
                arr[b/i]++;
            }
        }
        i++;
    }
    for(int i = 0; i < 101; i++){
        if(arr[i] == 2){
            v.push_back(i);
        }
    }
    sort(v.rbegin(), v.rend());
    cout << v[k-1];



}





///promy_pompom
//hello world
