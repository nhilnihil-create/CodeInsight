#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>
#include<list>

/*
MMNgmggMMMMNggmmMMMMMgmmmMMMMMmmmmMMMMMqmqmMMMMNqqqqMMMMNqkqkMMMMNkqkqMMMMNqqqmNMMMNqqmgMMMMNmmmHMMMMNmmgHMMMMNgggHMMMMNgggMMMMMNg
MMNggggMMMMMggggMMMMMggggMMMMMmggmMMMMMqqqqMMMNNkqkHMMMHBYY""""""YYUUWMMMNNkkqqMMMMNqqmHMMMMNmmmHMMMMNggmHMMMMNmggHMMMMMgggMMMMMMg
MMNggggMMMMMggggMMMMMggggMMMMMggmmMMMMMqqkkMH9"=!_..`.`.``.`.```.``.``.`.._??7YMMMNNqqqHMMMMNmgmHMMMMNgggHMMMMNgmgHMMMMNgggMMMMMMg
MMNggggMMMMNggggMMMMMggggMMMMMmmmmMMNM#Y=!.`.````````````.`````.`````.``````.```.._?7UWHMMNMNmmgHMMMMNgggHMMMMNgggMMMMMNgggMMMMMMg
MMNggggMMMMMgg@gMMMMMggggMMMMMmmqHT"!.````.``.``.`````.````````````````````````.``.```. ?TMMNmmmHNMMMNgggHMMMMNgggMMMMMM@@@MMMMMM@
MMN@@@@NMMMN@@ggMMMMM@gggMMMMMHY^``.``.````````.````````````````````````````````````.````.. ?TWqHMMMMNgggHMMMMNg@@MMMMMMgg@MMMMMMg
MMMg@@@MMMMMg@@gMMMMMggggMNMB=.``.``.``.```````````````````````````````````.`````````.``````..`-7HMNMNgggHMMMMNgg@MMMMMMgg@MMMMMM@
MMM@@@gMMMMN@@@@MMMMMgggmM"``.`.``.```````.```````````````````````````````````.``.`````.``.```....-TMNmggMMMMMNgg@MMMMMM@@@MMMMMM@
MMM@@@@NMMMM@@ggMMMMMggB=...``.``````.````````````````````````````````.````````````````````.`````....(THgHMMMMNg@@MMMMMM@@@MMMMMMg
MMM@@@@MMMMN@@@@MMMMM#=..`.`.``.`.`````.`````.```````.```.`````.``.``````.`````````````.``.``.`.``.`...-7HNMMNNg@@MMMMMM@@@MMMMMM@
MMM@@@@MMMMN@@@@MMNMY_..`.`.`.``.``..`````.``````.``.``````.````````.``.```.``.`..`.``.````.``.``.``.`..._WMMHSwz+??7TTBH@@MMMMMM@
MMM@@@@MMMMM@@@gMM@!...`.`.``.`.``.```.`.```.``.``````.`.```.`.``.````.`````.`` ~```````.`` _`.`.`.`.`..._.(HNNgg@MMMNgJ._?WMMMMM@
MMM@HH@MMMMN@@@gM3.....`.`.```.`.``.``._`.`.``.``.`.```.`.`````.`.`.````.`.````_``.``.``.`.` _`.``..`.`......?Mg@@MMMMMM@@Ha,TMMM@
MMM@H@HMMMMN@@gK~...`.`.`.`..``.`.``._````.``.``.``.`.```.`.`.``.```.. ``.``.. !``.``.`````   .`.```.``.`.....,Wg@MMMMMM@@@MMMNMM@
MMMH@H@MMMMM@gY ` ...`.`.``.`.``.` -``..`.`.``.``.``.`.`.```.`.``.``` ~`.``.``._`.``.`.`      ~`..`.`..`.`....  4gMMMMMM@H@MMMMMM@
MMM@HH@NMMMNH%`    .`..``.``.`.`..~.`.``.`.`.`..``.``.`.`.`.``..``..`_..`.`.``..`.`.          .-``..``..`.`.   ``?MMMMMM@HHMMMMMMH
MMMHH@HMMMNM\`` `    ``..`.`.``.._`.``.`.``.``.`.`.``.``.`.`.``.`.`..```.`.`` (         `   `  ~`.``..``      ` ``?NMMMMH@HMMMMMMH
MMM@H@HNMNM^` `              ``.    ..`.`.``.``.`.`..``.```..`.`.`..!.`.``.`...-       `       _.`..         `  `` dNMMM@H@MMMMMMH
MMMH@H@MMM^` ` ` `  ` ``    .`.``.`.``.`.`..`..``.``.`.`..``...``.`(`..`..`.`` !.`.``..   `     _.`..`.....  `  ` ` WNMMHHHMMMMMMH
MMMHHHHNM^` ` ` `   ...`...`.._`.`.`..`.`.`.`.`..` -`..``..` ~`..`.:``.``._`.``.`.`.`.``.`.. `  ~`.`.``.`......  ` `.MMMH@HMMMMMMH
MMMH@@HN%` ``  ......``.``..._`..`.`.`.`.`.`.`.`. _..`.`.`.`-.`...(~..`...<...`.`.``.`.``.``.`  _.`.`..``.``...... ``dNMHHHMMMMMMH
MMMHH@@F`  .......`....`..` ~.`..``.`.`...``.`.``_.`..`.`.` ~.``..;.``..`.;<.`.`.`..`.`..`.`.`. ~.`...`....`..........MMHHHMMMMMMH
MMMHHH#_.......`..``.`..`.._`..`..`..`..`.`...`..~.`.~..`..._..``(>.... !(;;_..`..`.`.`.`.`..`.._`.`..`.`...`.`._...._dM@HHMMMMMMH
MMMHHM%........`....`..`.`.~.`.`...`..``.`.`.`. <.`.<`.`.....`...;+.`.`.~(>;<-`..`.`.`.`..`._.`.~.`.._`..`.....`(_....(MHHHMMMMMMH
MMMHH@~.._<.....`.`..`..`._..`..``..`.`...`...`(_. +>..`.``(..`.(>j_.`.._(>>;<..`...`..`.`..<`.._.`.`<. <-`.`....:...._MHHHMMMMMMH
MMMHM>.~(d!......`.`.`.`. ~.`..`..`..`.`.`..`. :..(>:.`...-?....(<v_...._(;>;;<..`..`...`..(<.`._`...<.`<<...`...<.....d@HHMMMMMM#
MMMHD..(H@....`....`..`..-_`.`..`..`..`.`..`..-_.(;;>..`..(<_..`(j>>....<(>>>>;<-....`..`. (<.._...`-~..(;_.....`~...~.JHHHMMMMMM#
MMMM>~(dM%.....`.`..`..`._`...`..``.`..`..`..`(.-<;;>....-><_.`.(j:<-.`({(>>>>>;<-...`....(+<..<....(...(;<..`...~....~JHHHMMMMMM#
MMM#~_dN#_.......`..`....<..`.._....`...`...`.:.(;><c....(:<~...(l~<:..(1-<>>;>>><_....`.-+1:.-+_..-<.``+><......_.....(HHHMMMMMM#
MMMD~(HNE.........`..`.` ~.`..(:...`..`..`...-:-<>;++-.`.+<!?!~~?C>~<__(z;<<++1X>><-.....(;z?!1<---((-.(I>;_..---<...~.(HHHMMMMMM#
MMMl(MHN%.....`..`......._....;<.`.`.``..`.`.-<(;>+I<<..-><` ~..(z_``<.->1_;>>>II>>><_..->+z<.:._.-!._.(z;;_..(~(~....~(HH#MMMMMN#
MMM<dHHM:..._......`.`..(...`(+~........`....-<(>>j:~-_.-<<``._.-z``` <-><l(>>>I(+>>>>--+>+(<;`..-/`..(>I>>_..._(.....(dMM#NMMMMNN
MMN(##H#~.._<...`...`..(1..`-;+_.``.`.`......-:<>;v:``_-->~```(..<`````<(.<><>>1;1>>>>>>>+>o>``_./``((<:z>;<..(_:.....~JHNmWHMMMMM
MMNd##Hb...(~..`..`...-<+...(;>......`..`.`...>;;+><```<->_`.`.<-(._~!!!?!_<+>>1~<I>>>>>>c(z..(o/``.c!.<l;>~..;/.....~.dH##NMMMMMN
MMMM##HF.~_+.......`..(;(_.-;+~.`.`....`..`..`(>>j<~.jdWkkqqkqqqqqqqqHkkmx  (I>+-_?z>>>>+~Z((J+dQQQgaJ--z;>_.(<~_......d###NMMMMMN
MMN#N#H]..(<....`....(;~-_.(>>.`...`..`....`..-z;j:?UkH9=<<<`````JqqqHH7?7^`` 1+>` (+>>+!(?77!~dqHP?7HHl1><_.(!.<....._d##NNMMMMMN
MMMNN##t~_>>......`.-<!..<-<<_..`...`...`.....`<>z<``_4/~~``(.. (WVWUXH!```````.1-` <;+>-` `  .X0WP_~V` l><.-!.._...~.(M#NNMMMMMNN
MMMNNN#r.(1:.......`(<..`((+~..`..`..`...`.`...-z1:````_`` `jROzdyVWCOK``````````_``.z:````.RzWWZd\` ``.I;~(~...(_...~(N#NNMMMMMMN
MMMNNN#r~+1~...`...(<_...-v!.....`...`..`..`....(z<```````  .WZ<<?<<-g%``.`````````````````.R>?>.V```` JI>(_....._....JNNNNMMMMMMN
MMMNNNN]_?1.....`..(~..`.(~._.`...`...`..`..`.`..j<``.`` ` `` 7G+--+Z=``````.`````````````` SJ..d'  ``(z+>......._<..~dNNNNMMMMMMN
MMMNNNNb(?v.......-~....(_.-(_.`...`...`.....`....<```.``.........```````````````.``````.`````....... zC_....`....(_..dNNNMMMMMMMN
MMMMNMN#(?>......._....__..(;<_..`...`..`......`...<.`... ` ........``````````````````.```.`..`.....`.>>_...-......<.~dNNMNNMMMMMN
MMMNMNNMz?>.....`...`-_...-;;;<__...`....`.<-..`.`..<.`............`..`.``.``.``.``.``````!`.........(>>_...(_....._<_MNMNMMMMMMMM
MMMMNMNMbz<.........-~....+;;>>;__.....`..`.<+-.....`_-............````.```.``.`````.``.```.``......._z;_...(;_.....<.MMNMNMMMMMMN
MMMMNMMN#z~......`.-_....(;>>;>;;+-...`......~;1......-<.........`.`.`````.````. ......-(((((-(--.....1>~...>;<.....(_dNNNMMMMMMMM
MMMNMNMMMr.........(.....(;>>>>>>>+-.........._<+/~-...._-``.`.``.```.` ...-<<<<>+++++&&zz;;++++<;?<-.(>_.._z><.....(~(MNMNMMMMMNM
MMMMMNMMM%~.......-:....._;>>>>>>>>+-.....`....._+<` !~---((.`` ...(<<1+++xzOvvrvvrvvvvrrrz;+vrvvrrOz+v+.._+>><.....(.~dNNMMMMMMMM
MMMMMMNN#~.......-<1-.....(>1+>>>>>>>1-.........._(-````...(+zz&zz<;+vvvvvvvvvvvvvvvvvvvvvI;;OvvvvvvrrrrO&v?>>:....(~.~_WNNMMMMMMM
MMMMNMMNF~.~....(>>><-....._<>11+>>?>>+1-....._-((JOzvzvvvvrvvvvvZ;>zvvvvvvvzzzzzzzzzzzzzzw>>zvvvzvvzvvvvO<1x<.~.(jNx_~~~?MNMMMMMM
MMMMMNN#:....._(>>>>>>++-...._~<<zO&&&&&uwzwO<;+rvvvvvvvvvvvvvvvvI;+vvvvzvzzzzzzzzzzzzzzzzzz>+vvzzzzzzzzzv<+wn.(gMNMNNa-~~(TMNMMMM
MMMMMNM$..~..-<>>>>>>>+wrXZ<1wzzzvvvvvvzvvvvI;;jvvvvvvvvzzvzvzvvvz>jzzzzzzzzzzzzzzzzzzzzzzzI;+vzzzzzzzzzzzz>wzwMNMMMMMMNNgJ-_?TWMM
MMMMNM@~....(?>>>>>>>>zvvZ;;zvvzvvvvvvvzvvvw>;+wvvvvzzzzzzzzzzzzzz>zvzzzzzzuzzuzuzzuzzzzzzzI>>wzzzzzzzzzzzz>wuuuMNMMMMMMMMMMMMMMMM
MMMMN#<.~..(>>>?>>????zwvI;+vvvvvzvzvvvzzvvI;;jzvzvzzzzzzzzzzzzzz<>wvzzzzzzzuzzzzzzzzzzzzvzz>+rvwwOOOwwwvvz>wuuXMMMMMMMMMMMMMMMMMM
MMMNM3.~._(>?>?>>?>>>??Ovw;+vvvzvzzzzzzzzvZ<>+wvvzzzzzzzzzzzzzzzv>+zzzzzzuzzzzzzzzwOOC71<<>>;>>>>>>>>>>;>>>>+1wMNMMMMMMMMMMMMMMMMM
MMMM3~.._+>>?>>>?>?>?>?1VC<<1<<<>>>>>++1z71;>vOOOOOOOOOOOOOOOOOOC>+OOOCCCC71<<>>>>>>>>++xzZ>>zzzzzzzzzzzzI>+zz>MMMMMMMMMMMMMMMMMMM
MMM3.~._<>>?>?>>??>?>?1zO++;++&&&&&&&&&+++>>++++>>>>>>>>>>>>>;>>>>>>>+?+++++++&&zzwwzzzzzwz;+zzzzzzzzzzzzz>zZ!~(MMMMMMMMMMMMMMMMMM
MM:..._<?><<>>>>>?>?1v<++XO&ywzzzzzzzzzzzz<>jvzzzzzzzzzzzzzzzzzw<>jzzzzzzzzzzzzuuzzzzzzzzI>>zzzzuzuuzzzzZ>jV>+1-?MNMMMMMMMMMMMMMMM
#~..~_<><~(>>???>???z;jvvzzzzzzXUXuXXXXXXko&dkkXXXXXXXXXXXXXuuuI>>jzuuuuuuuuuuzuuzuuzuzuC>>juzuuzuXXXXkWUXUzvc;j_?MMMMMMMMMMMMMMMM
...~_<<!(<>>?>>>?>?1I+wvvvzzzzzzzzzzzzzuC7TuXpppppbbpbpbbbbbbbWuuuXpppWWkkkkkkkXXXXXXXXw&&&wkkWWbppppbWUUzvzzw>j~~(MNMMMMMMMMMMMMM
..~_<!.(>>?>>?>???1v<;>;>;><?zCOwzzzzzzC>+zzzzzzuUUUWWbbbpbbbbKuzuWbppbbbbbbpbbbbbbbbbWuuuXpbpbpbbbWUI>1zzvvvvzv.~._TMMMNMMMMMMMMM
.._<__(>>?>>?>??>1C<jzvwzz&++>>;>>+zOwC>;jzzzzzzuzuuzuzuuXUUWWWXuXbbbbbbbbbbbbbbbbbbbbSuuXpbbbbWUUzuzI>+vzzvvvO~....~(HNMMMMNMMMMM
...._<>?>>>?>?>?v<+wzvvzzzzzzzzwOz++>>>;+wzzuzzuzzzzuzzzzzuzzzw1>?XUUWWWpbbbbbbbbbbbpWuXXWWUUuzzzzzzzw>>wzzvvrC........?MNMMMMMMMM
...(>>>?>>?>???z;+wvzzzzzzzzzzzzzzzZ<;>++><?Cwzzzzzzzzuzzuzzzwz>>jzuzzuzzuuuuUUUUUVC1zzzzzzuuzuuzuzzzv<>zvvZz<1...~..~..~?MNMMMMMM
..(>>>>?>?>?>+ZwvXWWkkkXwwwuzzzzzwC>;>jzzzwz+>>+zOwzzzzzzzzzzI>>+zzzuzzuzzuzzuzuuzI>>>Ozuzzuzzzzzzzzzz<;zC<;;+O{...........?HNMMMM
.(>>>>?>>?>>j1>wvWppWpppppppppWkyz>;+zzzzzuzzzwz++>>+1COwzzzC>>+wzzzuzzzzuzzuzzzzzzz>>jzzzzzzzzzzzzzzZz;>;+xrvvw/........~..~?HNMM
(>>>>>>>?>+v?>??XXY~~~~<?TUWpfpWXzzwXXwzzuzzuuzzzzwO&+>>>>+1;;+wvzzzzzzuzzzzzzzzzzzI;>+wzzzzzzzzuzZC<>;>;OvvvvvrI.....__......~?MN
>>>>>?>?>+C>>>>>j>~~~~~~~~~~_?TSzzXpppppkkXuzuuzuzzzzzzwz&+;>;>>+zCOwzzzzzzuzzzzzzzI;;>OvzzzzzZC1>>++zvI>jvvvwwXt......-~_.~...~_T
*/

using namespace std;

using ll = long long int;
using ull = unsigned long long int;

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

ll mypow(ll x,ll n,ll mod = MOD){
    ll ret = 1;
    while(n > 0){
        if(n&1){
            ret = (ret*x)%mod;
        }
        x = (x*x)%mod;
        n >>= 1;
    }
    return ret;
}

ll mygcd(ll a,ll b){
    if(b == 0)return a;
    return mygcd(b,a%b);
}

ll twoPow(ll shiftNum){
    return (1LL << shiftNum);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    ll m,k;
    cin >> m >> k;

    if(k >= twoPow(m)){
        cout << -1 << endl;
        return 0;
    }

    if(m == 1){
        if(k == 0)
            cout << "0 0 1 1" << endl;
        else
            cout << -1 << endl;
        return 0;
    }

    vector<ll> ans(twoPow(m+1),0);
    
    for(int i = 0; i < twoPow(m); i++){
        ans[i] = i;
        if(i >= k){
            ans[i]++;
        }
    }

    ans[twoPow(m) - 1] = k;
    ans.back() = k;

    for(int i = twoPow(m+1) - 2,j = 0; j < twoPow(m) - 1;i--, j++){
        ans[i] = ans[j];
    }

    bool flag = false;
    for(const auto x:ans){
        if(flag)cout << " ";
        cout << x;
        flag = true;
    }

    cout << endl;

    return 0;
}