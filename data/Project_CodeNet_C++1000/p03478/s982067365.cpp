#include <iostream>
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#define int long long
using namespace std;
signed main() {
    int N,A,B;
    cin>>N>>A>>B;
    int ans=0;

    for(int i=1;i<=N;i++){
        if(i/10000+(i%10000/1000)+(i%10000%1000/100)+(i%10000%1000%100/10)+(i%10000%1000%100%10)>=A&&i/10000+(i%10000/1000)+(i%10000%1000/100)+(i%10000%1000%100/10)+(i%10000%1000%100%10)<=B){
            ans+=i;
        }
    }
    cout<<ans<<endl;
}
