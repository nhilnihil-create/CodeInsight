#include<iostream> 
#include<iomanip> 
#include<vector> 
#include<map> 
#include<set> 
#include<algorithm> 
#include<numeric> 
#include<limits> 
#include<bitset> 
#include<functional> 
#include<type_traits> 
#include<queue> 
#include<stack> 
#include<array> 
#include<random> 
#include<utility> 
#include<cstdlib> 
#include<ctime>
#define INT_MAX 2147483647
#define _LIBCPP_DEBUG 0
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (n); ++i)	
using namespace std;



int max(int a,int b) {
	int max;
	if (a > b) max = a;
	else max = b;
	return max;
}
int min(int a, int b) {
	int min;
	if (a < b) min = a;
	else min = b;
	return min;
}

int main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    int res = 0;
    for (int a = 0; a <= A; ++a) {
        for (int b = 0; b <= B; ++b) {
            for (int c = 0; c <= C; ++c) {
                int total = 500 * a + 100 * b + 50 * c; // 合計金額
                if (total == X) ++res; // 合計金額が X に一致したら答えをインクリメント
            }
        }
    }
    cout << res << endl;
}