#include <bits/stdc++.h>
#define mn(a, b) (a < b ? a : b)
#define mx(a, b) (a > b ? a : b)
#define f first
#define s second
#define all(v) (v).begin(), (v).end()
#define base 331

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int const MAXn = (1 << 18) + 2;

int arr[MAXn];

struct par{
    int num;
    int id;
    int num2;
    int id2;
}mask[MAXn];

bool cmp(pair < int , int > a, pair < int , int > b){
    return a.f > b.f;
}


void funt(int pos1, int pos2){
    if(!mask[pos2].num){
        mask[pos2] = mask[pos1];
        return;
    }
    vector < pair < int , int > > aux;
    if(mask[pos1].num) aux.push_back({mask[pos1].num, mask[pos1].id});
    if(mask[pos1].num2) aux.push_back({mask[pos1].num2, mask[pos1].id2});
    if(mask[pos2].num) aux.push_back({mask[pos2].num, mask[pos2].id});
    if(mask[pos2].num2) aux.push_back({mask[pos2].num2, mask[pos2].id2});
    sort(all(aux), cmp);
    mask[pos2].num = aux[0].f; mask[pos2].id = aux[0].s;
    int i = 1;
    while(i < aux.size() && mask[pos2].id == aux[i].s){
        i++;
    }
    if(i < aux.size()){
        mask[pos2].num2 = aux[i].f; mask[pos2].id2 = aux[i].s;
    }
}

int main(){

  
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0; i < (1 << n); i++){
        int x;
        cin>>x;
        mask[i].num = x, mask[i].id = i;
	}
	int sol = 0;
	for(int i = 0; i < (1 << n); i++){
        if(i > 0){
            sol = mx(sol, mask[i].num + mask[i].num2);
            cout<<sol<<"\n";
        }
        for(int j = 0; j < n; j++){
            if(!(i & (1 << j)))
                funt(i, (i ^ (1 << j)));
        }
	}
    return 0;
}
