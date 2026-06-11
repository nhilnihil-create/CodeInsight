#include <bits/stdc++.h>

using namespace std;

#define countof(a) (sizeof(a)/sizeof(*a))

#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pi >
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define all(n) n.begin(), n.end()

#define FROMTO(var, from, to) for (register int var = (from), var##down = ((int)(to)) < ((int)(from));var##down ? (var >= (int)(to)) : (var <= (int)(to));var##down ? var-- : var++)
#define UPTO(var, from, to)   for (register int var = (from); var <= ((int)to); var++)
#define DOWNTO(var, from, to) for (register int var = (from); var >= ((int)to); var--)
#define FOR(var, to)          UPTO(var, 0, (to)-1)
#define DOWN(var, from)       DOWNTO(var, (from)-1, 0) 

#define INIT(var, val) FOR(i,countof(var)) var[i] = val
#define INPUT(var) FOR(i,countof(var)) cin >> var[i]
#define INPUT1(var) FOR(i,countof(var)) cin >> var[i], var[i]--

#define SORT(v) qsort(v,countof(v),sizeof(*v),int_less)
#define SORTT(v) qsort(v,countof(v),sizeof(*v),int_greater)
#define QSORT(v,b) qsort(v,countof(v),sizeof(*v),b)

#define MOD 1000000007
#define INF ((1 << 30)-1)
#define LINF ((1LL << 62)-1)

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

struct Comb {
    vector<vector<s64> > data;
    Comb(int n) { // O(n^2)
        data = vector<vector<s64> >(n+1,vector<s64>(n+1,1));
        UPTO(i,1,n) {
            FOR(j,i+1) {
                if (!j || j == i) data[i][j] = 1;
                else data[i][j] = data[i-1][j-1] + data[i-1][j];
            }
        }
    }
    
    s64 ncr(int n, int r) {
        return data[n][r];
    }
};

static inline int ri() {
  int a;
  scanf("%d", &a);
  return a;
}

int int_less(const void *a, const void *b) {
  return (*((const int*)a) - *((const int*)b));
}
int int_greater(const void *a, const void *b) {
  return (*((const int*)b) - *((const int*)a));
}

int main() {
    int n = ri();
	int t = ri();
	int q = ri();
	vi a(n), s(n);
	FOR(i,n) a[i] = s[i] = ri();
	sort(all(s));
	
	int res = INF;
	FOR(i,n) {
		vvi v;
		int l = 0;
		FOR(j,n) {
			if (a[j] < s[i]) {
				if (l < j-1) v.push_back(vi(a.begin()+l,a.begin()+j));
				l = j+1;
			}
		}
		if (l != n) v.push_back(vi(a.begin()+l,a.begin()+n));
		vi p;
		for (auto& j : v) {
			sort(all(j));
			FOR(k,j.size()-t+1) p.push_back(j[k]);
		}
		if (p.size() >= (size_t)q) {
			sort(all(p));
			res = min(res,p[q-1]-s[i]);
		}
	}
	cout << res << endl;
    return 0;
}
