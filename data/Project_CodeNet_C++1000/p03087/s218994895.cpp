#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

#define INF  -10000000000

int main()
{
    int n,q;
    string s;
    int l[100005];
    int r[100005];
    vector<int> ans;
    
    cin >> n >> q;
    cin >> s;
    for (int i = 0;i < q;i++){
        cin >> l[i] >> r[i];
    }
    
    for (int i = 0;i < n-1;i++){
        if (s[i] == 'A' && s[i+1] == 'C'){
            ans.push_back(i+1);
        }
    }
    for (int i = 0;i < q;i++){
        auto iter1 = lower_bound(ans.begin(),ans.end(),l[i]);
        auto iter2 = lower_bound(ans.begin(),ans.end(),r[i]-1);
        auto chec1 = upper_bound(ans.begin(),ans.end(),l[i]);
        auto chec2 = upper_bound(ans.begin(),ans.end(),r[i]-1);
    
        if (iter2 != chec2){
            cout << (iter2-ans.begin()) - (iter1-ans.begin()) +1 << endl;
        }
        else{
            cout << (iter2-ans.begin())-(iter1-ans.begin()) << endl;
        }
    }
}
