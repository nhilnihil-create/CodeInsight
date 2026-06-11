#pragma GCC optimize ("O3")

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

using QWORD  = uint64_t;
using SQWORD = int64_t;
using DWORD  = uint32_t;
using SDWORD = int32_t;
using WORD   = uint16_t;
using SWORD  = int16_t;
using BYTE   = uint8_t;
using SBYTE  = int8_t;
using DOUBLE = double;
using FLOAT  = float;

#define MIN_SDWORD (-2147483648)
#define MAX_SDWORD (2147483647)
#define MIN_SBYTE (-128)
#define MAX_SBYTE (127)

#define MIN_SQWORD (0x8000000000000000)
#define MAX_SQWORD (0x7FFFFFFFFFFFFFFF)

#define MAX_QWORD  (0xFFFFFFFFFFFFFFFF)
#define MAX_DWORD  (0xFFFFFFFF)
#define MAX_WORD   (0xFFFF)
#define MAX_BYTE   (0xFF)


#define ArrayLength(a)  (sizeof(a) / sizeof(a[0]))

static inline QWORD MAX(QWORD a, QWORD b) { return a > b ? a : b; }
static inline DWORD MAX(DWORD a, DWORD b) { return a > b ? a : b; }
static inline SDWORD MAX(SDWORD a, SDWORD b) { return a > b ? a : b; }
static inline QWORD MIN(QWORD a, QWORD b) { return a < b ? a : b; }
static inline DWORD MIN(DWORD a, DWORD b) { return a < b ? a : b; }
static inline SDWORD MIN(SDWORD a, SDWORD b) { return a < b ? a : b; }

#define BYTE_BITS   (8)
#define WORD_BITS   (16)
#define DWORD_BITS  (32)
#define QWORD_BITS  (64)

using M_BOOL = bool;
#define M_TRUE (true)
#define M_FALSE (false)
#define DIVISOR (1000000007)

static inline void inputString(char *pcStr)
{
    char *pcCur = pcStr;
    for (;;) {
        char c = getchar();
        if (('\n' == c) || (EOF == c)) {
            break;
        }
        *pcCur = c;
        pcCur++;
    }
    *pcCur = '\0';
}


static inline SQWORD inputSQWORD(void)
{
    SQWORD sqNumber = 0;
    SQWORD sqMultiplier = 1;
    M_BOOL bRead = M_FALSE;
    for (;;) {
        char c = getchar();
        if (!bRead) {
            if ('-' == c) {
                sqMultiplier = -1;
            }
        }
        if (('0' <= c) && (c <= '9')) {
            sqNumber *= 10LL;
            sqNumber += (SQWORD)(c - '0');
            bRead = M_TRUE;
        } else {
            if (bRead) {
                return sqNumber * sqMultiplier;
            }
        }
    }
}


static inline SDWORD inputSDWORD(void)
{
    SDWORD lNumber = 0;
    SDWORD lMultiplier = 1;
    M_BOOL bRead = M_FALSE;
    for (;;) {
        char c = getchar();
        if (!bRead) {
            if ('-' == c) {
                lMultiplier = -1;
            }
        }
        if (('0' <= c) && (c <= '9')) {
            lNumber *= 10;
            lNumber += (c - '0');
            bRead = M_TRUE;
        } else {
            if (bRead) {
                return lNumber * lMultiplier;
            }
        }
    }
}

static inline DOUBLE inputFP(void)
{
    DOUBLE dInt = 0.0;
    DOUBLE dFrac = 0.0;
    DOUBLE dMultiplier = 1.0;
    DWORD dwFpCnt = 0;
    DOUBLE *pdCur = &dInt;
    M_BOOL bRead = M_FALSE;
    for (;;) {
        char c = getchar();
        if (!bRead) {
            if ('-' == c) {
                dMultiplier = -1;
            }
        }
        if ('.' == c) {
            pdCur = &dFrac;
        } else if (('0' <= c) && (c <= '9')) {
            (*pdCur) *= 10;
            (*pdCur) += (DOUBLE)(c - '0');
            bRead = M_TRUE;
            if (pdCur == &dFrac) {
                dwFpCnt++;
            }
        } else {
            if (bRead) {
                return dMultiplier * (dInt + dFrac / (pow((DOUBLE)10.0 , (DOUBLE)dwFpCnt)));
            }
        }
    }
}

#define N_MAX_MATCH (10000)

/* s1 > s2 か */
static bool isStringLarger(string &s1, string &s2) {
    if (s1.size() == s2.size()) {
        return (s2[0] < s1[0]); 
    } else {
        return (s2.size() < s1.size());
    }
}

static SQWORD s_asqNumMatches[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    SQWORD sqN = inputSQWORD();
    SQWORD sqM = inputSQWORD();

    vector<SQWORD> vecDigits;
    for (SQWORD sqIdx = 0; sqIdx < sqM; sqIdx++) {
        SQWORD sqA = inputSQWORD();
        vecDigits.emplace_back(sqA);
    } 

    /**
     *  dp[i] i本のマッチを使って作れる最大の整数
     * 
     */
    string  s_astrDp[N_MAX_MATCH + 1];
    for (SQWORD sqIdx = 0; sqIdx < ArrayLength(s_astrDp); sqIdx++) {
        s_astrDp[sqIdx] = string("");
    }

    for (SQWORD sqIdxMatch = 1; sqIdxMatch <= sqN; sqIdxMatch++) {
        string strNextDp = "";
        for (auto digit : vecDigits) {
            SQWORD sqNumMatchOne = s_asqNumMatches[digit];

            string strNewNumber = "";
            if (sqNumMatchOne <= sqIdxMatch) {
                SQWORD sqPrevDpIdx = sqIdxMatch - sqNumMatchOne;
                if (s_astrDp[sqPrevDpIdx] == "") {
                    if (sqIdxMatch == sqNumMatchOne) {
                        strNewNumber = to_string(digit);
                    }
                } else {
                    strNewNumber = to_string(digit) + s_astrDp[sqPrevDpIdx];
                }
            }
            if (isStringLarger(strNewNumber, strNextDp)) {
                strNextDp = strNewNumber;
            }                    
        }
//        printf("%lld %s\n", sqIdxMatch, strNextDp.c_str());
        s_astrDp[sqIdxMatch] = strNextDp;
    }

    printf("%s\n", s_astrDp[sqN].c_str());

    return 0;
}