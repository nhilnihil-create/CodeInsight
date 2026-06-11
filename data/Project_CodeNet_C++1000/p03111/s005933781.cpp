#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, A, B, C;
vector<int> l;

int ref(int depth, int a, int b, int c){
    if(depth==N){
        if(!a || !b || !c){
            return 99999;
        }
        return abs(a-A)+abs(b-B)+abs(c-C);
    }
    
    int ref1 = ref(depth+1, a, b, c);
    int ref2 = ref(depth+1, a+l[depth], b, c)+(a==0 ? 0: 10);
    int ref3 = ref(depth+1, a, b+l[depth], c)+(b==0 ? 0: 10);
    int ref4 = ref(depth+1, a, b, c+l[depth])+(c==0 ? 0: 10);
    
    return min({ref1, ref2, ref3, ref4});
}

int main(){
    cin >> N >> A >> B >> C;
    l.resize(N);
    for(int i=0; i<N; i++){
        cin >> l[i];
    }
    cout << ref(0, 0, 0, 0) << endl;
}