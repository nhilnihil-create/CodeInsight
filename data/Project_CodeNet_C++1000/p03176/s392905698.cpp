#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
class BIT{
    long long int tree[MAXN];
    int size;
    public:
    BIT(int n){
        size = n;
        for(int i = 0; i < MAXN; ++i){
            tree[i] = 0;
        }
    }    
    
    void print(){
        cout << "TREE : \n";
        for(int i = 0; i < size; ++i){
            cout << i << " \t " << tree[i] << "\n";
        }
    }
    
    long long int max1(int end){
        long long int max_val = -1;
        while(end > 0){
            max_val = max(max_val, tree[end]);
            end = end & (end - 1);
        }
        return max_val;
    }
    
    void update(int pos, long long int val){
        while(pos < MAXN){
            tree[pos] = max(val, tree[pos]);
            int last_set = pos & (-pos);
            pos += last_set;
        }
    }
    
    long long int max_tree_value(){
        long long int max_val = 0;
        for(int i = 1; i <= size; ++i){
            max_val = max(max_val, tree[i]);
        }
        return max_val;
    }
};

int main(){
    int n;
    cin >> n;
    
    int heights[MAXN], beauts[MAXN];
    
    for(int i = 0; i < n; ++i){
        cin >> heights[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> beauts[i];
    }
    
    BIT tree(n);
    for(int i = 0; i < n; ++i){
        int height = heights[i];
        long long int beaut = beauts[i];
        long long int max_yet = tree.max1(height);
        
        tree.update(height, max_yet + beaut);
    }
    
    cout << tree.max_tree_value() << "\n";
}
