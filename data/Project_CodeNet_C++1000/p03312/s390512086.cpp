#include <iostream>
#include <algorithm>
#include <vector>

/* 累積和クラス */
template <class Type_ElementsA, class Type_ElementsS>
class Cumulative_Sum{
private:
    const int n;
    std::vector<Type_ElementsA> A;
    std::vector<Type_ElementsS> S;
public:
    Cumulative_Sum(int nn): n(nn){
        A.resize(nn); S.resize(nn+1);
    }
    Cumulative_Sum(std::vector<Type_ElementsA> &AA): n(A.size()){
        A = AA;
    }
    void input_VecInt(void){
        for(int i = 0; i < n; ++i) scanf("%d", &A[i]);
    }
    void input_VecLong(void){
        for(int i = 0; i < n; ++i) scanf("%lld", &A[i]);
    }
    /* Aの内容からSの計算 */
    void previous(void){
        S[0] = 0; for(int i = 0; i < n; ++i) S[i+1] = S[i] + A[i];
    }
    Type_ElementsS sumOf(int k){
        return S[k];
    }
    /* 区間[left, right]の値 */
    Type_ElementsS between(int left, int right){
        return S[right+1] - S[left];
    }
};


int main(void){
    int n; scanf("%d", &n);
    Cumulative_Sum<int, long long int> D(n);
    D.input_VecInt(); D.previous();
    /* k番目の切り込み ; A[k]とA[k+1]の間　(0 ≤ k < n-1) */
    int left = 0, medium = 1, right = 2;
    long long int A[4];
    long long int res = 2e18+1;
    while(medium + 1 < n-1){
        while(left + 2 <= medium){
            long long int TD = abs(D.between(0, left) - D.between(left+1, medium));
            long long int ND = abs(D.between(0, left+1) - D.between(left+2, medium));
            if(TD < ND) break;
            left++;
        }
        while(right + 2 <= n-1){
            long long int TD = abs(D.between(medium+1, right) - D.between(right+1, n-1));
            long long int ND = abs(D.between(medium+1, right+1) - D.between(right+2, n-1));
            if(TD < ND) break;
            right++;
        }
        A[0] = D.between(0, left);
        A[1] = D.between(left+1, medium);
        A[2] = D.between(medium+1, right);
        A[3] = D.between(right+1, n-1);
        std::sort(A, A+4);
        long long diff = A[3] - A[0];
        if(res > diff) res = diff;
        medium++;
    }
    printf("%lld\n", res);
}