#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

int main()
{
	LL N, K;
	in >> N >> K;
	std::vector<LL>A(N), B(N);
	rep(i, N) in >> A[i] >> B[i];

	LL ans = 0;
	for (LL i = 30; i >= 0; --i)
	{
		if (K&(1LL << i)) //もしもKのibit目が1だったら
		{
            //max は ibit目より下が1で埋まっている
			LL max = (K ^ (1LL << i)) | ((1LL << i) - 1), res = 0;
			rep(j, N)//各A[j]について
			{
				bool flag = true;
				rep(k, 31)// k=0 ~ 30について
				{
                    // kbit目についてもしもA[j]が1なのに maxが0だったらだめ
					if ((A[j] & (1LL << k)) && !(max&(1LL << k)))
					{
						flag = false;
						break;
					}
				}
				if (flag) res += B[j];
			}
			ans = std::max(ans, res);
		}
	}
	LL res = 0;
	rep(i, N) //各A[i]について
	{
        //これは常にKのビットと比較する
		bool flag = true;
		rep(j, 31)//j=0~30 jビット目について考える 
		{
            //もしもA[i]のjビット目が1 かつ Kのjビット目が立っていなかったらだめ ORを取るから
			if ((A[i] & (1LL << j)) && !(K&(1LL << j)))
			{
				flag = false;
				break;
			}
		}
        //A[i]の各ビットは全てKに含まれる
		if (flag) res += B[i];
	}
	ans = std::max(ans, res);

	out << ans << std::endl;
}
