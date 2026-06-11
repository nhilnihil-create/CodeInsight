#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct BIT{
    int size;
    vector<int> bit;
    void init(int n){
        size = n;
        bit.assign(size+1, 0);
    }

    // from 1 to x (inclusive)
    int sum(int x){
        int res = 0;
        while(x > 0){
            res += bit[x];
            x -= (x & -x);
        }
        return res;
    }

    void add(int x, int y){
        while(x <= size){
            bit[x] += y;
            x += (x & -x);
        }
    }
};

long long inv_num(int n, vector<int> array){
    long long res = 0;
    vector<int> v;
    BIT b;
    b.init(n);
    v.assign(array.begin(), array.end());
    sort(v.begin(), v.end());
    auto tmp = unique(v.begin(), v.end());
    v.erase(tmp, v.end());
    for(int i=0;i<n;i++){
        int val = (int)(lower_bound(v.begin(), v.end(), array[i]) - v.begin()) + 1;
        res += i - b.sum(val);
        b.add(val, 1);
    }
    return res;
}

bool judge(long long n, int *ar, int x){
    vector<int> v;
    v.push_back(0);
    for(int i=0;i<n;i++){
        int t = 1;
        if(*(ar+i) < x)t = -1;
        v.push_back(v[i] + t);
    }
    long long y = n*(n+1)/2 - inv_num(n+1, v);
    /*cout << n << " " << x << " " << inv_num(n+1, v) << endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;*/
    return (y >= (n*(n+1)/2+1)/2);
}

int main(void){
    int n, left, right;
    int ar[100000];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> ar[i];
    }
    left = 1;
    right = 1e9+1;
    while(left + 1 < right){
        int mid = (left + right) / 2;
        if(judge(n, ar, mid)){
            left = mid;
        }else{
            right = mid;
        }
    }
    cout << left << endl;
}
