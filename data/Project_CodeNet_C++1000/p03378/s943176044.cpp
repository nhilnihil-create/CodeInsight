#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits> // FOO_MAX, FOO_MIN
#include <cmath> 
#include <cstdlib> // abs(int), labs(long int), llabs(llint)

#define roundup(n,d) ( ((n) + ((d)-1)) / (d) )
#define ll long long

using namespace std;

int main(void){
    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a(m);
    for(int i = 0;i < m;i++){
        cin >> a[i];
    }

    int tall_count = 0;
    for(int i = 0;i < m;i++){
        if(a[i] >= x){
            break;
        }
        tall_count++;
    }

    cout << min(tall_count, m-tall_count) << endl;
    return 0;
}