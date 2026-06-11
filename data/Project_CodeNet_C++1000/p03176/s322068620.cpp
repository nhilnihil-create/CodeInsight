#include<bits/stdc++.h>
using namespace std;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}


typedef pair<int, int> pii;

const int MAX = 200005;
int h[MAX];
int n;
long long a[MAX], dp[MAX];

typedef struct item * pitem;

struct item {
    int key, prior;
    long long val, maximo = 0;
    item * l, * r;
    item() { }
    item (int key, int prior, long long val) : key(key), prior(prior), l(NULL), r(NULL), val(val){ }
};

typedef item * pitem;

long long maximo (pitem t) {
    return t ? t-> maximo : 0;
}

void upd_maximo (pitem t) {
    if (t)
        t->maximo = max(t->val, max(maximo(t->l), maximo(t->r)));
}

void split (pitem t, int key, pitem & l, pitem & r) {
    if (!t)
        l = r = NULL;
    else if (key <= t->key)
        split (t->l, key, l, t->l),  r = t;
    else
        split (t->r, key, t->r, r),  l = t;
    upd_maximo(t);
}

void insert (pitem & t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split (t, it->key, it->l, it->r),  t = it;
    else
        insert (it->key < t->key ? t->l : t->r, it);
    upd_maximo(t);
}

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_maximo(t);
}

void erase (pitem & t, int key) {
    if (t->key == key)
        merge (t, t->l, t->r);
    else
        erase (key < t->key ? t->l : t->r, key);
    upd_maximo(t);
}

long long query(pitem &t, int h){
    pitem l, r;
    split(t, h, l, r);
    long long ans = maximo(l);
    merge(t, l, r);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));

    cin>>n;
    for(int i = 0; i<n; ++i){
        cin>>h[i];
    }
    for(int i = 0; i<n; ++i){
        cin>>a[i];
    }

    long long val, rta = 0;
    pitem treap = NULL;
    for(int i = 0; i<n; ++i){
        val = query(treap, h[i]);
        //error(val, i);
        val+=a[i];
        pitem p = new item(h[i], rand(), val);
        insert(treap, p);
        rta = max(rta, val);

    }
    cout<<rta<<"\n";
}
